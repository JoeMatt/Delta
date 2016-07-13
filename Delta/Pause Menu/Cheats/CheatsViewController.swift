//
//  CheatsViewController.swift
//  Delta
//
//  Created by Riley Testut on 5/20/16.
//  Copyright © 2016 Riley Testut. All rights reserved.
//

import UIKit
import CoreData

import DeltaCore

import Roxas

protocol CheatsViewControllerDelegate: class
{
    func cheatsViewControllerActiveEmulatorCore(_ saveStatesViewController: CheatsViewController) -> EmulatorCore
    func cheatsViewController(_ cheatsViewController: CheatsViewController, didActivateCheat cheat: Cheat) throws
    func cheatsViewController(_ cheatsViewController: CheatsViewController, didDeactivateCheat cheat: Cheat)
}

class CheatsViewController: UITableViewController
{
    weak var delegate: CheatsViewControllerDelegate! {
        didSet {
            self.updateFetchedResultsController()
        }
    }
    
    private var backgroundView: RSTBackgroundView!
    
    private var fetchedResultsController: NSFetchedResultsController<AnyObject>!
}

extension CheatsViewController
{
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        self.title = NSLocalizedString("Cheats", comment: "")
        
        self.backgroundView = RSTBackgroundView(frame: self.view.bounds)
        self.backgroundView.isHidden = false
        self.backgroundView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        self.backgroundView.textLabel.text = NSLocalizedString("No Cheats", comment: "")
        self.backgroundView.textLabel.textColor = UIColor.white()
        self.backgroundView.detailTextLabel.text = NSLocalizedString("You can add a new cheat by pressing the + button in the top right.", comment: "")
        self.backgroundView.detailTextLabel.textColor = UIColor.white()
        self.tableView.backgroundView = self.backgroundView
        
        self.registerForPreviewing(with: self, sourceView: self.tableView)
    }
    
    override func viewWillAppear(_ animated: Bool)
    {
        self.fetchedResultsController.performFetchIfNeeded()
        
        self.updateBackgroundView()
        
        super.viewWillAppear(animated)
    }

    override func didReceiveMemoryWarning()
    {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

//MARK: - Navigation -
private extension CheatsViewController
{
    @IBAction func unwindFromEditCheatViewController(_ segue: UIStoryboardSegue)
    {
        
    }
}

//MARK: - Update -
private extension CheatsViewController
{
    func updateFetchedResultsController()
    {
        let game = self.delegate.cheatsViewControllerActiveEmulatorCore(self).game as! Game
        
        let fetchRequest = Cheat.fetchRequest()
        fetchRequest.returnsObjectsAsFaults = false
        fetchRequest.predicate = Predicate(format: "%K == %@", Cheat.Attributes.game.rawValue, game)
        fetchRequest.sortDescriptors = [SortDescriptor(key: Cheat.Attributes.name.rawValue, ascending: true)]
        
        self.fetchedResultsController = NSFetchedResultsController(fetchRequest: fetchRequest, managedObjectContext: DatabaseManager.sharedManager.managedObjectContext, sectionNameKeyPath: nil, cacheName: nil)
        self.fetchedResultsController.delegate = self
    }
    
    func updateBackgroundView()
    {
        if let fetchedObjects = self.fetchedResultsController.fetchedObjects where fetchedObjects.count > 0
        {
            self.tableView.separatorStyle = .singleLine
            self.backgroundView.isHidden = true
        }
        else
        {
            self.tableView.separatorStyle = .none
            self.backgroundView.isHidden = false
        }
    }
}

//MARK: - Managing Cheats -
/// Managing Cheats
private extension CheatsViewController
{
    @IBAction func addCheat()
    {
        let editCheatViewController = self.makeEditCheatViewController(cheat: nil)
        editCheatViewController.presentWithPresentingViewController(self)
    }
    
    func deleteCheat(_ cheat: Cheat)
    {
        self.delegate.cheatsViewController(self, didDeactivateCheat: cheat)
        
        let backgroundContext = DatabaseManager.sharedManager.backgroundManagedObjectContext()
        backgroundContext.perform {
            let temporaryCheat = backgroundContext.object(with: cheat.objectID)
            backgroundContext.delete(temporaryCheat)
            backgroundContext.saveWithErrorLogging()
        }
    }
}

//MARK: - Convenience -
/// Convenience
private extension CheatsViewController
{
    func configure(cell: UITableViewCell, forIndexPath indexPath: IndexPath)
    {
        let cheat = self.fetchedResultsController.object(at: indexPath) as! Cheat
        cell.textLabel?.text = cheat.name
        cell.textLabel?.font = UIFont.boldSystemFont(ofSize: cell.textLabel!.font.pointSize)
        cell.accessoryType = cheat.enabled ? .checkmark : .none
    }
    
    func makeEditCheatViewController(cheat: Cheat?) -> EditCheatViewController
    {
        let editCheatViewController = self.storyboard!.instantiateViewController(withIdentifier: "editCheatViewController") as! EditCheatViewController
        editCheatViewController.delegate = self
        editCheatViewController.supportedCheatFormats = self.delegate.cheatsViewControllerActiveEmulatorCore(self).supportedCheatFormats
        editCheatViewController.cheat = cheat
        editCheatViewController.game = self.delegate.cheatsViewControllerActiveEmulatorCore(self).game as! Game
        
        return editCheatViewController
    }
}

extension CheatsViewController
{
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int
    {
        let numberOfSections = self.fetchedResultsController.sections!.count
        return numberOfSections
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        let section = self.fetchedResultsController.sections![section]
        return section.numberOfObjects
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: RSTGenericCellIdentifier, for: indexPath)
        self.configure(cell: cell, forIndexPath: indexPath)
        return cell
    }
}

extension CheatsViewController
{
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath)
    {
        let cheat = self.fetchedResultsController.object(at: indexPath) as! Cheat
        
        let backgroundContext = DatabaseManager.sharedManager.backgroundManagedObjectContext()
        backgroundContext.performAndWait {
            let temporaryCheat = backgroundContext.object(with: cheat.objectID) as! Cheat
            temporaryCheat.enabled = !temporaryCheat.enabled
            
            if temporaryCheat.enabled
            {
                do
                {
                    try self.delegate.cheatsViewController(self, didActivateCheat: temporaryCheat)
                }
                catch EmulatorCore.CheatError.invalid
                {
                    print("Invalid cheat:", cheat.name, cheat.code)
                }
                catch let error as NSError
                {
                    print("Unknown Cheat Error:", error, cheat.name, cheat.code)
                }
            }
            else
            {
                self.delegate.cheatsViewController(self, didDeactivateCheat: temporaryCheat)
            }
            
            
            backgroundContext.saveWithErrorLogging()
        }
        
        self.tableView.reloadRows(at: [indexPath], with: .none)
    }
    
    override func tableView(_ tableView: UITableView, editActionsForRowAt indexPath: IndexPath) -> [UITableViewRowAction]?
    {
        let cheat = self.fetchedResultsController.object(at: indexPath) as! Cheat
        
        let deleteAction = UITableViewRowAction(style: UITableViewRowActionStyle(), title: NSLocalizedString("Delete", comment: "")) { (action, indexPath) in
            self.deleteCheat(cheat)
        }
        
        let editAction = UITableViewRowAction(style: .normal, title: NSLocalizedString("Edit", comment: "")) { (action, indexPath) in
            let editCheatViewController = self.makeEditCheatViewController(cheat: cheat)
            editCheatViewController.presentWithPresentingViewController(self)
        }
        
        return [deleteAction, editAction]
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath)
    {
        // This method intentionally left blank because someone decided it was a Good Idea™ to require this method be implemented to use UITableViewRowActions
    }
}

//MARK: - <UIViewControllerPreviewingDelegate> -
extension CheatsViewController: UIViewControllerPreviewingDelegate
{
    func previewingContext(_ previewingContext: UIViewControllerPreviewing, viewControllerForLocation location: CGPoint) -> UIViewController?
    {
        guard let indexPath = self.tableView.indexPathForRow(at: location) else { return nil }
        
        let frame = self.tableView.rectForRow(at: indexPath)
        previewingContext.sourceRect = frame
        
        let cheat = self.fetchedResultsController.object(at: indexPath) as! Cheat
        
        let editCheatViewController = self.makeEditCheatViewController(cheat: cheat)
        return editCheatViewController
    }
    
    func previewingContext(_ previewingContext: UIViewControllerPreviewing, commit viewControllerToCommit: UIViewController)
    {
        let editCheatViewController = viewControllerToCommit as! EditCheatViewController
        editCheatViewController.presentWithPresentingViewController(self)
    }
}

//MARK: - <EditCheatViewControllerDelegate> -
extension CheatsViewController: EditCheatViewControllerDelegate
{
    func editCheatViewController(_ editCheatViewController: EditCheatViewController, activateCheat cheat: Cheat, previousCheat: Cheat?) throws
    {
        try self.delegate.cheatsViewController(self, didActivateCheat: cheat)
        
        if let previousCheat = previousCheat
        {
            let code = cheat.code
            
            previousCheat.managedObjectContext?.performAndWait({
                
                guard previousCheat.code != code else { return }
                
                self.delegate.cheatsViewController(self, didDeactivateCheat: previousCheat)
            })
        }
    }
    
    func editCheatViewController(_ editCheatViewController: EditCheatViewController, deactivateCheat cheat: Cheat)
    {
        self.delegate.cheatsViewController(self, didDeactivateCheat: cheat)
    }
}

//MARK: - <NSFetchedResultsControllerDelegate> -
extension CheatsViewController: NSFetchedResultsControllerDelegate
{
    func controllerDidChangeContent(_ controller: NSFetchedResultsController<NSFetchRequestResult>)
    {
        self.tableView.reloadData()
        self.updateBackgroundView()
    }
}
